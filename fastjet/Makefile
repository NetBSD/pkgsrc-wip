# $NetBSD: Makefile,v 1.1 2012/09/12 17:25:41 jihbed Exp $
#

DISTNAME=	fastjet-3.0.3
CATEGORIES=	math #physics
MASTER_SITES=	http://fastjet.fr/repo/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fastjet.fr/
COMMENT=	Software package for jet finding in pp and e+e- collisions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP= configure plugins/SISCone/siscone/configure \
			configure.lineno
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash
USE_LANGUAGES=	c c++ fortran

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	fastjet-config.in


#CONFIGURE_ARGS+=	--enable-cgal

#.include "../../math/cgal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
