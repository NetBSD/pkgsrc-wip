# $NetBSD: Makefile,v 1.1 2015/04/25 20:52:55 krytarowski Exp $

DISTNAME=	libunwind-1.1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/libunwind/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.savannah.gnu.org/releases/libunwind/
COMMENT=	Generic stack unwinding library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libunwind-generic.pc.in
PKGCONFIG_OVERRIDE+=	src/ptrace/libunwind-ptrace.pc.in
PKGCONFIG_OVERRIDE+=	src/setjmp/libunwind-setjmp.pc.in
PKGCONFIG_OVERRIDE+=	src/coredump/libunwind-coredump.pc.in
PKGCONFIG_OVERRIDE+=	src/unwind/libunwind.pc.in

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
