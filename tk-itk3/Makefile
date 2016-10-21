# $NetBSD: Makefile,v 1.8 2014/02/22 08:25:04 obache Exp $
#

DISTNAME=	itk3.4.2
PKGNAME=	tk-${DISTNAME:S/itk/itk3-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	Framework for building mega-widgets for Tcl/Tk
LICENSE=	mit # Standard ML of New Jersey Variant

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ARGS+=	--with-itcl=${BUILDLINK_PREFIX.tcl-itcl3}/lib
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/itk3
USE_TOOLS+=		grep

WRKSRC=		${WRKDIR}/${DISTNAME:R}

# Remove conflict with itk 4.x
post-install:
.for file in Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n
	${RUN} cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann/ && \
		${MV} ${file} itk3-${file}
.endfor

.include "../../wip/tcl-itcl3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
