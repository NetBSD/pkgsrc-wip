# $NetBSD: Makefile,v 1.3 2013/03/04 21:58:38 thomasklausner Exp $
#

DISTNAME=	itextrups-1.0.2
PKGNAME=	java-${DISTNAME:tu:S/ITEXT/iText-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=itextrups/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lowagie.com/iText/
COMMENT=	Reading and Updating PDF Syntax tool from iText
LICENSE=	gnu-agpl-v3

DEPENDS+=	java-itext-[0-9]*:../../wip/iText

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

MESSAGE_SUBST+=	DN=itext-rups-${PKGVERSION_NOREV}

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/itext-rups-${PKGVERSION_NOREV}.jar ${DESTDIR}${PREFIX}/lib/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
