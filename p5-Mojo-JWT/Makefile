# $NetBSD: Makefile,v 1.139 2018/09/02 07:55:30 wiz Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Mojo-JWT-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/JBERGER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Mojo::JWT
COMMENT=	JSON Web Token the Mojo way
LICENSE=	${PERL_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojo/JWT/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
