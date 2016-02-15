# $NetBSD$

DISTNAME=	libpwquality-1.3.0
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/libpwquality/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	https://fedorahosted.org/releases/l/i/libpwquality/
COMMENT=	Library for generating random passwords and quality checking
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		automake autoconf aclocal gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-pam
CONFIGURE_ARGS+=	--with-python-binary=${PYTHONBIN}

pre-configure: 
	set -e; cd ${WRKSRC}; \
	aclocal; \
	autoconf; \
	automake

.include "../../wip/py-cracklib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
