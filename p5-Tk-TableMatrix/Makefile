# $NetBSD: Makefile,v 1.2 2003/09/16 15:45:56 jmmv Exp $
#

DISTNAME=	Tk-TableMatrix-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tkt
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Table/Matrix widget extension to Perl/Tk

USE_BUILDLINK2=		YES
USE_X11=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/TableMatrix/.packlist

CPPFLAGS+=		${BUILDLINK_CPPFLAGS.p5-Tk}

.include "../../lang/perl5/module.mk"
.include "../../x11/p5-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
