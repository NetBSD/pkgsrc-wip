# $NetBSD: Makefile,v 1.6 2005/12/02 16:19:44 jmmv Exp $
#

DISTNAME=	Tk-TableMatrix-1.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tkt
CATEGORIES=	x11 tk perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tk/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Table/Matrix widget extension to Perl/Tk

DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

CPPFLAGS+=		-I${PERL5_SITEARCH}/Tk/pTk
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tk/TableMatrix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
