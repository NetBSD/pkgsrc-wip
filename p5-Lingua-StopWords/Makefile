# $NetBSD: Makefile,v 1.3 2012/10/04 18:42:20 asau Exp $

DISTNAME=	Lingua-StopWords-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Lingua-StopWords/
COMMENT=	Lingua::StopWords - Stop words for several languages

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST= auto/Lingua/StopWords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
