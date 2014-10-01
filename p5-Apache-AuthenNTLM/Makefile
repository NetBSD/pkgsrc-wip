# $NetBSD: Makefile,v 1.6 2014/10/01 10:40:52 thomasklausner Exp $

DISTNAME=	Apache-AuthenNTLM-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~speeves/
COMMENT=	Perl5/Apache module for NTLM authorization

DEPENDS+=	p5-MIME-Base64>=3:../../converters/p5-MIME-Base64

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Apache/AuthenNTLM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
