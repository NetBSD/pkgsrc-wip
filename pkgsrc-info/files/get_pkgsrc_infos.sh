#!/bin/sh

# NOTE: stat not portable

set -e
export LC_TIME=C
OS=$(uname -s)
PKG_ROOT=$(cd .. && pwd)
PKGSRC_ROOT=$(cd "../../.." && pwd)

if [ ! -f "${PKGSRC_ROOT}/doc/pkgsrc.txt" ]; then
    echo "PKGSRC_ROOT(=$PKGSRC_ROOT) fail"
    exit 1
else
    cd ${PKGSRC_ROOT}
fi

if [ -d ".git" ]; then
    git config --global --add safe.directory "${PKGSRC_ROOT}"
    VCS="git"
elif [ -d ".hg" ]; then
    VCS="mercurial"
elif [ -d "CVS" ]; then
    VCS="cvs"
fi

last_changed() {
    case "$OS" in
        NetBSD|FreeBSD|OpenBSD|DragonFly|Darwin)
            find . \( -type d -name "CVS" \
                    -o -type d -name "wip" \
                    -o -type d -name "distfiles" \
                    -o -type d -name "work" \
                    -o -type d -name "packages" \) -prune \
                -o -type f -print0 | xargs -0 stat -f '%m %N' | sort -n | tail -1 | cut -d' ' -f2-
            ;;
        Linux|SunOS)
            find . \( -type d -name "CVS" \
                    -o -type d -name "wip" \
                    -o -type d -name "distfiles" \
                    -o -type d -name "work" \
                    -o -type d -name "packages" \) -prune \
                -o -type f -print0 | xargs -0 stat -c '%Y %n' | sort -n | tail -1 | cut -d' ' -f2-
            ;;
        *)
            # fallback
            ls -tr doc/ | tail -1
            ;;
    esac
}

last_time() {
    case "$OS" in
        NetBSD|FreeBSD|OpenBSD|DragonFly|Darwin)
            date -j -f "%a %b %d %T %Y" \
                "$(grep $(basename "$1") $(dirname "$1")/CVS/Entries | cut -d/ -f4)" \
                "+%F %T %z"
            ;;
        Linux)
            date -d "%a %b %d %T %Y" \
                "$(grep $(basename "$1") $(dirname "$1")/CVS/Entries | cut -d/ -f4)" \
                "+%F %T %z"
            ;;
        *)
            grep $(basename "$1") $(dirname "$1")/CVS/Entries | cut -d/ -f4
            ;;
    esac
}

case "$VCS" in
    git)
        BRANCH=$(git rev-parse --abbrev-ref HEAD)
        LAST_HASH=$(git log -1 --format=%H)
        LAST_DATE=$(git log -1 --format=%ci)
        ;;
    mercurial)
        BRANCH=$(hg branch)
        LAST_HASH=$(hg log -l 1 --template "{node}\n")
        LAST_DATE=$(hg log -l 1 --template "{date|isodate}\n")
        ;;
    cvs)
        BRANCH=$(cvs status -v "doc/pkgsrc.txt" \
                | sed -n 's/.*Sticky Tag:\t*\(.*\)/\1/p' \
                | cut -d' ' -f1)
        if [ "$BRANCH" = "(none)" ]; then
            BRANCH="trunk"
        fi
        LAST_HASH=$(last_changed)
        LAST_DATE=$(last_time ${LAST_HASH})
        ;;
esac

MYSQL=$(sed -n 's|MYSQL_VERSION_DEFAULT?=.*\t\(.*\)|\1|p' mk/mysql.buildlink3.mk)
PGSQL=$(sed -n 's|PGSQL_VERSION_DEFAULT?=.*\t\(.*\)|\1|p' mk/pgsql.buildlink3.mk)
NODE=$(sed -n 's|NODE_VERSION_DEFAULT?=.*\t\(.*\)|\1|p' lang/nodejs/nodeversion.mk)

sed -e "s|@VCS@|$VCS|g" \
    -e "s|@BRANCH@|$BRANCH|g" \
    -e "s|@CREF@|$LAST_HASH|g" \
    -e "s|@CDATE@|$LAST_DATE|g" \
    -e "s|@MYSQL@|$MYSQL|g" \
    -e "s|@PGSQL@|$PGSQL|g" \
    -e "s|@NODE@|$NODE|g" \
    "${PKG_ROOT}/work/pkgsrc-info.sh.in" > "${PKG_ROOT}/work/pkgsrc-info.sh"

exit 0
