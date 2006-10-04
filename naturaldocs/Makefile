# $NetBSD: Makefile,v 1.1.1.1 2006/10/04 11:54:25 ondratu Exp $
#

DISTNAME=	NaturalDocs-1.35
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=naturaldocs/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.naturaldocs.org/
COMMENT=	Open-source, extensible, multi-language documentation generator

USE_TOOLS+=     perl:run
REPLACE_PERL+=  NaturalDocs
PERL5_REQD+=	5.5

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

NDDIR=		${PREFIX}/NaturalDocs

INSTALL_DIRS=	Info JavaScript Modules Modules/NaturalDocs Modules/NaturalDocs/Builder \
		Modules/NaturalDocs/ClassHierarchy Modules/NaturalDocs/Languages \
		Modules/NaturalDocs/Languages/Advanced Modules/NaturalDocs/Languages/Prototype \
		Modules/NaturalDocs/Menu Modules/NaturalDocs/Parser Modules/NaturalDocs/Project \
		Modules/NaturalDocs/Settings Modules/NaturalDocs/SymbolTable \
		Modules/NaturalDocs/Topics Styles Config Help Help/example Help/images \
		Help/images/header Help/images/menu Help/javascript 

do-install:
	for dir in ${INSTALL_DIRS}; do \
                ${INSTALL_DATA_DIR} ${NDDIR}/$$dir; \
        done
	for dir in ${INSTALL_DIRS}; do                                  \
                for file in "${WRKSRC}/$$dir"/*; do                     \
                        ${INSTALL_DATA} $$file ${NDDIR}/$$dir;          \
                done                                                    \
        done
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${NDDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs.bat ${NDDIR}
	${INSTALL_DATA} ${WRKSRC}/License-GPL.txt ${NDDIR}


.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
