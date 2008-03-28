# $NetBSD: Makefile,v 1.1.1.1 2008/03/28 00:04:43 rhialto Exp $

PKGNAME=		p5-qt3-3.009b2
DISTNAME=		PerlQt-3.009-b2
#DISTNAME=		PerlQt-3.009-b1
#DISTNAME=		PerlQt-3.008
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=perlqt/}
COMMENT=		Perl-5 bindings for the Qt3 library

CATEGORIES=		x11
COMMENT=		Perl binding for Qt3
WRKSRC=			${WRKDIR}/PerlQt-3.009
HOMEPAGE=		http://perlqt.sourceforge.net/

USE_LANGUAGES+=		c++
USE_TOOLS+=		perl
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

PERL5_CONFIGURE_DIRS+=	. PerlQt

# There is more than just in the perl module's packlist
#PERL5_PACKLIST= auto/Qt/.packlist

# Build-time only:
BUILDLINK_DEPMETHOD.kdelibs=    build

.include "../../lang/perl5/module.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
