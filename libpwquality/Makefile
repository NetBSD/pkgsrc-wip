# $NetBSD$

DISTNAME=	libpwquality-1.3.0
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libpwquality/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for generating random passwords and quality checking
HOMEPAGE=	https://fedorahosted.org/libpwquality/
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		automake autoconf aclocal gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-pam
CONFIGURE_ARGS+=	--with-python-binary=${PYTHONBIN}

# XXX what to do with the conf files?
EGDIR=		python
CONF_FILES=	${EGDIR}/security/pwquality.conf ${PKG_SYSCONFDIR}/security/pwquality.conf

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; \
	autoconf; \
	automake

.include "../../wip/py-cracklib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
