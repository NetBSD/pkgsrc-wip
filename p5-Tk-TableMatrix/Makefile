# $NetBSD: Makefile,v 1.1.1.1 2003/07/29 13:56:42 jmmv Exp $
#

DISTNAME=	Tk-TableMatrix-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tkt
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Table/Matrix widget extension to Perl/Tk

DEPENDS+=	p5-Tk>=800.024:../../x11/p5-Tk

USE_X11=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/TableMatrix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
