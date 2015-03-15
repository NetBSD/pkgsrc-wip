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
USE_LIBTOOL=		no
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

BAREOS_GROUP?=          bareos
BAREOS_DIR_USER?=       bareos-dir
BAREOS_SD_USER?=        bareos-sd

.include "../../mk/bsd.prefs.mk"
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

