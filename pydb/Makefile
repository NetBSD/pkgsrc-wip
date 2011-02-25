# $NetBSD: Makefile,v 1.6 2011/02/25 09:47:50 thomasklausner Exp $
#

DISTNAME=	pydb-1.26
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bashdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	splitscreen@users.sourceforge.net
HOMEPAGE=	http://sourceforge.net/projects/bashdb/
COMMENT=	The Extended Python Debugger

DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../wip/py-ipython

PKG_DESTDIR_SUPPORT= 	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=	# none

PKG_OPTIONS_VAR=                PKG_OPTIONS.pydb
PKG_SUPPORTED_OPTIONS=          pyreadline
PKG_SUGGESTED_OPTIONS=          pyreadline

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpyreadline)
.include "../../devel/py-readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pyreadline
.endif


PYTHON_VERSIONS_ACCEPTED= 27 26 25
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
