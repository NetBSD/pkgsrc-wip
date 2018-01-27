# $NetBSD: Makefile,v 1.3 2014/12/30 22:51:59 makoto Exp $

PKG_FAIL_REASON=	"Not packaged yet (MASTER_SITES changed)"

DISTNAME=	rosegarden-14.12
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rosegardenmusic.com/
COMMENT=	Notation editor & MIDI sequencer
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake makedepend pkg-config
MAKE_ENV+=	GCC=yes
USE_LANGUAGES+=	c c++
#CXXFLAGS+=	-Ig++/tr1_impl

INSTALLATION_DIRS+=	bin lib/X11/app-defaults

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../wip/dssi/buildlink3.mk"
#.include "../../wip/libdssialsacompat/buildlink3.mk"
#.include "../../audio/liblo/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
