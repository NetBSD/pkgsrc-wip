# $NetBSD: Makefile,v 1.12 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	pydb-1.26
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bashdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	splitscreen@users.sourceforge.net
HOMEPAGE=	http://sourceforge.net/projects/bashdb/
COMMENT=	The Extended Python Debugger

DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

PKG_OPTIONS_VAR=		PKG_OPTIONS.pydb
PKG_SUPPORTED_OPTIONS=		pyreadline
PKG_SUGGESTED_OPTIONS=		pyreadline

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpyreadline)
DEPENDS+=		${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
CONFIGURE_ARGS+=	--enable-pyreadline
.endif

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ipython

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
