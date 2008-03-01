# $NetBSD: Makefile,v 1.4 2008/03/01 23:47:04 hoka_adam Exp $

DISTNAME=		DBD-ODBC-1.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		geeogeegeeoh@users.sourceforge.net
COMMENT=		DBD module interfacing the ODBC databases

DEPENDS+=		p5-DBI-*:../../databases/p5-DBI
DEPENDS+=		unixodbc-*:../../databases/unixodbc

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=		-o ${PREFIX}

PERL5_PACKLIST=		auto/DBD/ODBC/.packlist

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
