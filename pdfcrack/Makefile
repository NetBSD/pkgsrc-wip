# $NetBSD: Makefile,v 1.1 2015/03/02 17:07:37 leot1990 Exp $

DISTNAME=	pdfcrack-0.14
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfcrack/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://pdfcrack.sourceforge.net/
COMMENT=	Password Recovery Tool for PDF-files
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake	# FIXME: remove gmake dependency.

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing CFLAGS
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/CFLAGS/ s/-O3 -g//'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdfcrack ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pdfcrack.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
