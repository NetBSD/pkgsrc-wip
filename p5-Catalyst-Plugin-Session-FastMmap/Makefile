# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:30 asau Exp $

DISTNAME=	Catalyst-Plugin-Session-FastMmap-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}
PERL5_REQD+=	5.6.0

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-FastMmap/
COMMENT=	FastMmap sessions for Catalyst

DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-Cache-FastMmap>=0:../../devel/p5-Cache-FastMmap
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-URI-Find>=0:../../www/p5-URI-Find
DEPENDS+=	p5-Digest-MD5>=0:../../security/p5-Digest-MD5
DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable


PERL5_PACKLIST= auto/Catalyst/Plugin/Session/FastMmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
