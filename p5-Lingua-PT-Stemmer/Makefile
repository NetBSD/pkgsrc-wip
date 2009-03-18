# $NetBSD: Makefile,v 1.4 2009/03/18 12:06:12 cheusov Exp $

DISTNAME=	Lingua-PT-Stemmer-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Lingua-PT-Stemmer/
COMMENT=	Stemmers for Portuguese and Galician

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= 	auto/Lingua/PT/Stemmer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
