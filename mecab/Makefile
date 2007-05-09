# $NetBSD: Makefile,v 1.4 2007/05/09 13:21:09 obache Exp $

.include "Makefile.common"

DISTNAME=	mecab-${MECAB_VERSION}
DISTFILES=	#empty

COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

DEPENDS+=	{mecab-ipadic>=2.7.0,mecab-jumandic>=5.1}:../../wip/mecab-ipadic

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	#empty

.include "../../wip/mecab-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
