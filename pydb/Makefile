# $NetBSD: Makefile,v 1.9 2013/06/04 07:45:24 thomasklausner Exp $
#

DISTNAME=	pydb-1.26
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bashdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	splitscreen@users.sourceforge.net
HOMEPAGE=	http://sourceforge.net/projects/bashdb/
COMMENT=	The Extended Python Debugger

DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../wip/py-ipython

GNU_CONFIGURE=		yes
USE_LANGUAGES=	# none

PKG_OPTIONS_VAR=                PKG_OPTIONS.pydb
PKG_SUPPORTED_OPTIONS=          pyreadline
PKG_SUGGESTED_OPTIONS=          pyreadline

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpyreadline)
DEPENDS+=		${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
CONFIGURE_ARGS+=	--enable-pyreadline
.endif

PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
