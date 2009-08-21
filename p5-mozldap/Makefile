# $NetBSD: Makefile,v 1.1.1.1 2009/08/21 04:01:16 udontknow Exp $
#

DISTNAME=	perl-mozldap-1.5.2
PKGNAME=	p5-mozldap-1.5.2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_MOZILLA:=directory/perldap/releases/1.5.2/src/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.perldap.org/
COMMENT=	Mozilla implementation of LDAP support libraries for Perl
LICENSE=	gnu-gpl-v1 OR gnu-lgpl-v2.1 OR mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	LDAPSDKDIR=${PREFIX}
MAKE_ENV+=	LDAPSDKINCDIR=${PREFIX}/include/ldap
MAKE_ENV+=	LDAPSDKLIBDIR=${PREFIX}/lib
MAKE_ENV+=	LDAPSDKSSL=Y
MAKE_ENV+=	LDAPPR=Y
MAKE_ENV+=	NSPRDIR=${PREFIX}
MAKE_ENV+=	NSPRINCDIR=${PREFIX}/include/nspr
MAKE_ENV+=	NSPRLIBDIR=${PREFIX}/lib
MAKE_ENV+=	NSSDIR=${PREFIX}
MAKE_ENV+=	NSSLIBDIR=${PREFIX}/lib

PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../wip/mozldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
