# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:26 kristerw Exp $
#

DISTNAME=		FXPy-1.0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/FXPy/fox/}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fxpy/}

MAINTAINER= 		pkg@burningsoda.com
HOMEPAGE=		http://fxpy.sourceforge.net/
COMMENT=		Python bindings for the FOX toolkit

PYDISTUTILSPKG=		YES

pre-configure:
	@cd ${WRKSRC} && for f in setup.py; do			\
		${SED} "s,@PKGDIR@,${LOCALBASE},"		\
		$$f > $$f.tmp &&				\
		${MV} $$f.tmp $$f;				\
	done

.include "../../x11/fox/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
