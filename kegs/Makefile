# $NetBSD: Makefile,v 1.8 2009/08/07 23:43:25 thomasklausner Exp $
#

DISTNAME=	kegs.0.91
PKGNAME=	kegs-0.91
CATEGORIES=	emulators
MASTER_SITES=	http://kegs.sourceforge.net/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://kegs.sourceforge.net/
COMMENT=	Apple IIgs emulator for Mac OS X, Win32, Linux, and Unix/X11

# Official support
ONLY_FOR_PLATFORM=	Linux-*-i386 Linux-*-ppc SunOS-*-i386 SunOS-*-sparc Darwin-*-* HPUX-*-*
# Probably work
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-ppc *-*-x86_64 *-*-ia64 *-*-mips *-*-m68k
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_TOOLS+=     gmake perl
INSTALLATION_DIRS+=	bin share/doc/${PKGBASE} share/${PKGBASE}

pre-build:
	if [ -L ${WRKSRC}/vars ]; then ${RM} ${WRKSRC}/vars; fi
	@${ECHO} Building for ${OPSYS} on ${MACHINE_ARCH}...
	@case "${OPSYS}_${MACHINE_ARCH}" in				\
	Linux_ppc) ${LN} -s ${WRKSRC}/vars_linuxppc ${WRKSRC}/vars; break;;\
	Linux_i386) ${LN} -s ${WRKSRC}/vars_x86linux ${WRKSRC}/vars; break;;\
	SunOS_sparc*) ${LN} -s ${WRKSRC}/vars_solaris ${WRKSRC}/vars; break;;\
	SunOS_i386) ${LN} -s ${WRKSRC}/vars_x86solaris ${WRKSRC}/vars; break;;\
	Darwin*) ${LN} -s ${WRKSRC}/vars_mac ${WRKSRC}/vars; break;;	\
	HPUX*) ${LN} -s ${WRKSRC}/vars_hp ${WRKSRC}/vars; break;;	\
	*_i386) ${ECHO} "${OPSYS} on ${MACHINE_ARCH} is not officially supported, but ought to work..."; ${LN} -s ${WRKSRC}/vars_x86linux ${WRKSRC}/vars; break;;\
	*_ppc) ${ECHO} "${OPSYS} on ${MACHINE_ARCH} is not officially supported, but ought to work..."; ${LN} -s ${WRKSRC}/vars_linuxppc ${WRKSRC}/vars; break;;\
	*_amd64|*_ia64|*_x86_64) ${ECHO} "${MACHINE_ARCH} is not supported, but might work..."; ${LN} -s ${WRKSRC}/vars_x86linux ${WRKSRC}/vars; break;;\
	*_mips|*_m68k) ${ECHO} "${MACHINE_ARCH} is not supported, but might work..."; ${LN} -s ${WRKSRC}/vars_linuxppc ${WRKSRC}/vars; break;;\
	*) ${ECHO} Your platform is not recognized. ;;			\
	esac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../xkegs ${DESTDIR}${PREFIX}/bin/xkegs
	${INSTALL_DATA} ${WRKSRC}/../*txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/../config.kegs ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
