DISTNAME=	bareos-Release-14.2.3
PKGNAME=	bareos-14.2.3
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/bareos/bareos/archive/Release/${DISTNAME:S/bareos-Release-//}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	paul@paulbsd.com
HOMEPAGE=	http://www.bareos.org/
COMMENT?=	Open Source data protection
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

BAREOS_GROUP?=          bareos
BAREOS_DIR_USER?=       bareos-dir
BAREOS_SD_USER?=        bareos-sd

PKG_GROUPS_VARS+=       BAREOS_GROUP
PKG_USERS_VARS=         BAREOS_DIR_USER BAREOS_SD_USER

PKG_SYSCONFSUBDIR?=     bareos
BAREOS_PIDDIR?=         ${VARBASE}/run
BAREOS_WORKINGDIR?=     ${VARBASE}/spool/bareos

BUILD_DEFS+=            VARBASE BAREOS_PIDDIR BAREOS_WORKINGDIR

FILES_SUBST+=           BACULA_ETCDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=           BACULA_PIDDIR=${BACULA_PIDDIR}
FILES_SUBST+=           BACULA_GROUP=${BACULA_GROUP}
FILES_SUBST+=           BACULA_DIR_USER=${BACULA_DIR_USER}
FILES_SUBST+=           BACULA_SD_USER=${BACULA_SD_USER}

SUBST_CLASSES+=         egdir
SUBST_STAGE.egdir=      pre-configure
SUBST_FILES.egdir=      src/dird/Makefile.in
SUBST_FILES.egdir+=     src/console/Makefile.in
SUBST_FILES.egdir+=     src/filed/Makefile.in
SUBST_FILES.egdir+=     src/stored/Makefile.in
SUBST_FILES.egdir+=     src/gnome2-console/Makefile.in
SUBST_FILES.egdir+=     src/wx-console/Makefile.in
SUBST_FILES.egdir+=     src/tray-monitor/Makefile.in
SUBST_SED.egdir=        -e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g'

CONFLICTS=		bacula-[0-9]*

.include "../../wip/bareos/options.mk"

CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=        --with-scriptdir=${PREFIX}/libexec/bareos
CONFIGURE_ARGS+=        --with-sbin-perm=0755
CONFIGURE_ARGS+=        --with-working-dir=${BAREOS_WORKINGDIR}
CONFIGURE_ARGS+=        --with-pid-dir=${BAREOS_PIDDIR}
CONFIGURE_ARGS+=        --with-readline=${BUILDLINK_PREFIX.editlinereadline}/include/readline

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=        --enable-smartalloc
.endif
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=        --disable-xattr
.endif

PTHREAD_OPTS+=          require
PTHREAD_AUTO_VARS=      yes

.include "../../mk/bsd.pkg.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

