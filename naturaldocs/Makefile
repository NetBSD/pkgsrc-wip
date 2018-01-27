# $NetBSD: Makefile,v 1.4 2012/10/03 16:37:16 asau Exp $
#

DISTNAME=	NaturalDocs-1.35
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=naturaldocs/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.naturaldocs.org/
COMMENT=	Open-source, extensible, multi-language documentation generator

USE_TOOLS+=	perl:run
REPLACE_PERL+=	NaturalDocs
PERL5_REQD+=	5.5

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	pax

NDDIR=		${PREFIX}/NaturalDocs

INSTALL_DIRS=	Info JavaScript Modules Modules/NaturalDocs Modules/NaturalDocs/Builder \
		Modules/NaturalDocs/ClassHierarchy Modules/NaturalDocs/Languages \
		Modules/NaturalDocs/Languages/Advanced Modules/NaturalDocs/Languages/Prototype \
		Modules/NaturalDocs/Menu Modules/NaturalDocs/Parser Modules/NaturalDocs/Project \
		Modules/NaturalDocs/Settings Modules/NaturalDocs/SymbolTable \
		Modules/NaturalDocs/Topics Styles Config Help Help/example Help/images \
		Help/images/header Help/images/menu Help/javascript
INSTALLATION_DIRS= \
		${NDDIR}

do-install:
	cd ${WRKSRC} && pax -wr * ${DESTDIR}${NDDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${DESTDIR}${NDDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs.bat ${DESTDIR}${NDDIR}
	${INSTALL_DATA} ${WRKSRC}/License-GPL.txt ${DESTDIR}${NDDIR}


.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
