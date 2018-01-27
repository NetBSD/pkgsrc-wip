# $NetBSD: Makefile,v 1.1 2015/04/25 13:40:31 gschwarz Exp $
#

DISTNAME=	nrg4iso-1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/nrg4iso/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://code.google.com/p/nrg4iso/
COMMENT=	Extracts data from a Nero Burning ROM image file
LICENSE=	modified-bsd

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/nrg4iso
BUILD_TARGET=
INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		nospec
SUBST_STAGE.nospec=	post-patch
SUBST_FILES.nospec=	Makefile
SUBST_SED.nospec=	-e 's/^CC/\#CC/g' -e 's/^CFLAGS/\#CFLAGS/g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg4iso ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
