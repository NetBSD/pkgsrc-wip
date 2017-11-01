# $NetBSD$

DISTNAME=	libpwquality-1.3.0
CATEGORIES=	security
MASTER_SITES=	https://ftp.osuosl.org/pub/blfs/conglomeration/libpwquality/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for generating random passwords and quality checking
HOMEPAGE=	https://github.com/libpwquality/libpwquality
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		automake autoconf aclocal gmake
GNU_CONFIGURE=		yes

CONFIG_DIR=		share/examples/pwquality

CONFIGURE_ARGS+=	--disable-pam
CONFIGURE_ARGS+=	--with-python-binary=${PYTHONBIN}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${CONFIG_DIR}

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/security

PKGCONFIG_OVERRIDE=	src/pwquality.pc.in

PY_PATCHPLIST=	yes

CONF_FILES=	${CONFIG_DIR}/security/pwquality.conf \
			${PKG_SYSCONFDIR}/security/pwquality.conf

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; \
	autoconf; \
	automake

.include "../../wip/py-cracklib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
