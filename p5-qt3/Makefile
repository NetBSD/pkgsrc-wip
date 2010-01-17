# $NetBSD: Makefile,v 1.7 2010/01/17 12:03:29 thomasklausner Exp $

PKGNAME=		p5-qt3-3.009b2
DISTNAME=		PerlQt-3.009-b2
#DISTNAME=		PerlQt-3.009-b1
#DISTNAME=		PerlQt-3.008
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=perlqt/}
COMMENT=		Perl-5 bindings for the Qt3 library

PKGREVISION=		1
CATEGORIES=		x11
MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://perlqt.sourceforge.net/

USE_LANGUAGES+=		c
USE_LANGUAGES+=		c++
USE_TOOLS+=		perl
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_CONFIGURE_DIRS+=	. PerlQt
WRKSRC=			${WRKDIR}/PerlQt-3.009

# There is more than just in the perl module's packlist
PERL5_PACKLIST=		auto/Qt/.packlist

# Build-time only:
BUILDLINK_DEPMETHOD.kdelibs=	build

.include "../../lang/perl5/module.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
