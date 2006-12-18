# $NetBSD: Makefile,v 1.1 2006/12/18 18:59:53 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog.common"

PKGNAME=heirloom-common-${HEIRLOOM_VER}

NO_BUILD=	yes

INSTALLATION_DIRS=${DOC_DIR} ${DOC_DIR}/LICENSE ${PREFIX}
.for i in bin/posix bin/posix2001 bin/s42 bin etc/default etc lib/spell \
          lib/tmac lib man/man1 man/man1b man/man1m man/man2 man/man3 \
          man/man4 man/man5 man/man6 man/man7 man/man8 man sbin ucb \
          var/adm var/log var
INSTALLATION_DIRS+=	${PREFIX}/${HLROOT}/${i}
.endfor

do-install:

.include "../../mk/bsd.pkg.mk"
