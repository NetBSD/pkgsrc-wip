# $NetBSD: Makefile,v 1.1.1.1 2005/08/26 21:30:30 kuli0020 Exp $

DISTNAME=	Email-MIME-Encodings-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/C/CW/CWEST/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Encodings
COMMENT=	A unified interface to MIME encoding and decoding

DEPENDS+=	p5-MIME-Base64>=0.00:../../converters/p5-MIME-Base64

PERL5_PACKLIST= auto/Email/MIME/Encodings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
