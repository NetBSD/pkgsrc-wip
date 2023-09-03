# $NetBSD$

PKGNAME=		HP1973-0.0
DISTNAME=		HP1973-Source
CATEGORIES=		emulators
MASTER_SITES=		https://sarahkmarr.com/
EXTRACT_SUFX=		.zip

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://sarahkmarr.com/retrohp1973.html
COMMENT=		HP-45 emulator
LICENSE=		generic-nonlicense

RESTRICTED=		No hosting permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_LANGUAGES=		# none

# \todo wrong path?
REPLACE_PYTHON+=	HP1973.py

# \todo tkinter
DEPENDS+=		${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

do-build:
	${TRUE}

INSTALLATION_DIRS=	bin share/HP1973

do-install:
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} HP1973.py ${DESTDIR}/${PREFIX}/bin && \
	${INSTALL_DATA} *json ${DESTDIR}/${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
