# $NetBSD: Makefile,v 1.10 2013/03/04 21:58:38 thomasklausner Exp $
#

DISTNAME=	xmlworker-1.2.1
PKGNAME=	java-itext-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlworker/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lowagie.com/iText/
COMMENT=	Java classes to generate and parse XML files
LICENSE=	gnu-agpl-v3

DEPENDS+=	java-itext-[0-9]*:../../wip/iText

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

MESSAGE_SUBST+=	DN=${DISTNAME}

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
