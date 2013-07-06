# $NetBSD: Makefile,v 1.1 2013/07/06 15:35:48 makoto Exp $
#
DISTNAME=		simulavr-1.0.0
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.gnu.org/releases/simulavr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers
LICENSE=		gnu-gpl-v2

BROKEN=			"Just on the way, see TODO file, thanks.'
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--enable-python=python2.7
CONFIGURE_ARGS+=	--with-bfd=${PREFIX}/avr
#CONFIGURE_ENV+=		ac_cv_prog_has_texi2dvi=yes ac_cv_prog_has_texi2html=yes
USE_TOOLS+=		makeinfo
USE_LANGUAGES+=		c c++

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../wip/avr-binutils/buildlink3.mk"
.include "../../wip/avr-gcc/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
