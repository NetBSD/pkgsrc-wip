# $NetBSD$

DISTNAME=	html-xml-utils-7.4
CATEGORIES=	textproc
MASTER_SITES=	https://www.w3.org/Tools/HTML-XML-utils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.w3.org/Tools/HTML-XML-utils/
COMMENT=	Simple utilities for manipulating HTML and XML files
LICENSE=	w3c

GNU_CONFIGURE=	yes
USE_TOOLS+=	lex yacc

USE_LANGUAGES=	c99

REPLACE_SH+=	hxcite-mkbib

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
