# $NetBSD: Makefile,v 1.4 2009/03/18 12:12:58 cheusov Exp $

DISTNAME=		Lingua-Stem-Snowball-Da-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/~cine/Lingua-Stem-Snowball-Da-1.01/Da.pm
COMMENT=		Stemmer for Danish

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/Da/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
