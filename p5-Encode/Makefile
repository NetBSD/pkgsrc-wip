# $NetBSD: Makefile,v 1.1.1.1 2005/08/31 15:34:49 kuli0020 Exp $

DISTNAME=	Encode-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~dankogai/Encode/
COMMENT=	Provides interfaces between strings and the rest of the system

PERL5_REQD+=    5.8.0

PERL5_PACKLIST= auto/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
