# $NetBSD: Makefile,v 1.1.1.1 2004/03/25 15:10:00 poppnk Exp $

DISTNAME=		classpath-0.07
PKGNAME=		classpath-nox11-0.07
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/gnu/classpath/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/classpath
COMMENT=		Class libraries for Java VM

DEPENDS+=		jikes>=1.18:../../lang/jikes

GNU_CONFIGURE=		yes
INFO_FILES=		hacking.info vmintegration.info
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-jikes
CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
