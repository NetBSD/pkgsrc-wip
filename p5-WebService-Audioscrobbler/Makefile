# $NetBSD: Makefile,v 1.8 2012/10/04 19:12:04 asau Exp $

DISTNAME=	WebService-Audioscrobbler-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NI/NILSONSFJ/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://www.last.fm/api
COMMENT=	Interface to the Audioscrobbler WebService API (aka Last.FM)

DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor-[0-9]*:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/WebService/Audioscrobbler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
