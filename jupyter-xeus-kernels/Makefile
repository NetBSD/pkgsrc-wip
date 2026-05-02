# $NetBSD: Makefile,v 1.61 2025/12/18 21:22:59 maya Exp $

DISTNAME=	jupyter-xeus-kernels-20260425
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	matthewd@fastmail.us
COMMENT=	All of the Jupyter-Xeus kernels

META_PACKAGE=	yes

DEPENDS+=	xeus-lua-[0-9]*:../../wip/xeus-lua
DEPENDS+=	xeus-octave-[0-9]*:../../wip/xeus-octave
DEPENDS+=	xeus-python-[0-9]*:../../wip/xeus-python
DEPENDS+=	xeus-r-[0-9]*:../../wip/xeus-r
DEPENDS+=	xeus-sql-[0-9]*:../../wip/xeus-sql
DEPENDS+=	xeus-sqlite-[0-9]*:../../wip/xeus-sqlite

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
