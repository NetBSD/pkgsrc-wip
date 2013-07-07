# $NetBSD: Makefile,v 1.2 2013/07/07 03:42:12 makoto Exp $
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

# Interim fix
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fix include path finding Python.h
SUBST_FILES.prefix=	src/Makefile.in
SUBST_VARS.prefix=	PREFIX

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../wip/avr-binutils/buildlink3.mk"
.include "../../wip/avr-gcc/buildlink3.mk"
#.include "../../wip/avr-libc/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
