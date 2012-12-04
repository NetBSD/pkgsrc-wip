# $NetBSD: Makefile,v 1.12 2012/12/04 18:59:10 othyro Exp $
#

DISTNAME=	itext-5.3.4
PKGNAME=	java-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=itext/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lowagie.com/iText/
COMMENT=	Java classes to generate PDF files on the fly
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

MESSAGE_SUBST+=	PKGV_NR=${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	lib/java share/doc/${PKGBASE}

do-install:
		cd ${WRKSRC} && \
			${INSTALL_DATA} *${PKGVERSION_NOREV}.jar ${DESTDIR}${PREFIX}/lib/java && \
			${INSTALL_DATA} notice.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
