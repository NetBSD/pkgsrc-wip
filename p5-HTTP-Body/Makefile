# $NetBSD: Makefile,v 1.5 2007/10/26 07:48:48 jgoamakf Exp $

DISTNAME=	HTTP-Body-0.9
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AG/AGRUNDMA/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Body/
COMMENT=	HTTP Body Parser
PERL5_REQD+=	5.6.1

BUILD_DEPENDS+=	p5-File-Temp>=0.14:../../devel/p5-File-Temp
BUILD_DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

PERL5_PACKLIST= auto/HTTP/Body/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
