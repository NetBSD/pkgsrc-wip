# $NetBSD: Makefile,v 1.3 2004/05/14 13:59:24 thomasklausner Exp $
#

DISTNAME=	Tk-TableMatrix-1.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tkt
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Table/Matrix widget extension to Perl/Tk

USE_BUILDLINK3=		YES
USE_X11=		YES
CPPFLAGS+=		-I${PERL5_SITEARCH}/Tk/pTk
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/TableMatrix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/p5-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
