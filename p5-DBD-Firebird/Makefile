# $NetBSD$

DISTNAME=	DBD-Firebird-1.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://metacpan.org/pod/DBD::Firebird
COMMENT=	DBI driver for Firebird RDBMS server
LICENSE=	${PERL5_LICENSE}

DEPENDS=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

MAKE_ENV+=	FIREBIRD_INCLUDE=${PREFIX}/include

.include "../../lang/perl5/module.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../wip/firebird50/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
