# $NetBSD: Makefile,v 1.1.1.1 2005/09/14 10:59:40 vstakhov Exp $
#

DISTNAME=	gajim-0.8
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org
COMMENT=	Jabber client written in PyGTK

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PY_PATCHPLIST=	yes
USE_TOOLS=	gmake
MAKE_ENV=	"MAKE=gmake"

PATCH_MAKEFILE=	src src/common

post-patch:
.for i in ${PATCH_MAKEFILE}
	@${CP} ${WRKSRC}/${i}/Makefile ${WRKSRC}/${i}/Makefile.bak
	@${SED} -e 's,/usr/include,${LOCALBASE}/include,g' ${WRKSRC}/${i}/Makefile.bak > ${WRKSRC}/${i}/Makefile
.endfor

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
