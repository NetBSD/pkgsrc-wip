# $NetBSD: Makefile,v 1.2 2012/11/13 22:25:29 othyro Exp $
#

DISTNAME=	AGILe-1.4.0
PKGNAME=	agile-1.4.0
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/agile/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://agile.hepforge.org/
COMMENT=	Interface for a variety of Fortran-based Monte Carlo generators
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run
USE_LANGUAGES=	c c++ fortran

PKG_OPTIONS_VAR=                PKG_OPTIONS.agile
PKG_SUPPORTED_OPTIONS=          pyext
#PKG_SUGGESTED_OPTIONS=      pyext

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpyext)
PYTHON_VERSIONS_ACCEPTED= 32 31 27 26 25
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pyext
.endif

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	bin/agile-config.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/hepmc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
