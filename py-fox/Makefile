# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:59 tvierling Exp $
#

DISTNAME=		FXPy-1.0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/FXPy/fox/}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fxpy/}

MAINTAINER= 		pkg@burningsoda.com
HOMEPAGE=		http://fxpy.sourceforge.net/
COMMENT=		Python bindings for the FOX toolkit

USE_X11=		YES
PYDISTUTILSPKG=		YES

pre-configure:
	@cd ${WRKSRC} && for f in setup.py; do			\
		${SED} "s,@PKGDIR@,${LOCALBASE},"		\
		$$f > $$f.tmp &&				\
		${MV} $$f.tmp $$f;				\
	done

.include "../../x11/fox/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
