# $NetBSD: Makefile,v 1.1.1.1 2003/10/30 05:32:32 minskim Exp $

DISTNAME=	gdick-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://ddt.mirstyle.org/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://ddt.mirstyle.org/gdick.html
COMMENT=	English-Korean Dictionary Client for GNOME2

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

NO_CONFIGURE=	yes

post-patch:
.for f in gdick gdick_applet lib/gdick/gdick.py lib/gdick/YahooDict.py
	cd ${WRKSRC}; ${MV} $f $f.orig; \
	${SED} -e \
		's,/usr/,${LOCALBASE}/,g' \
		$f.orig > $f
.endfor

.include "../../x11/py-gnome2/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
