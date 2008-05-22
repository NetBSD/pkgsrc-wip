# $NetBSD: Makefile,v 1.2 2008/05/22 21:23:00 tnn2 Exp $

DISTNAME=	Authen-Htpasswd-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Authen-Htpasswd/
COMMENT=	Authen::Htpasswd - interface to read and modify Apache .htpasswd files

DEPENDS+=	p5-IO-LockedFile>=0:../../devel/p5-IO-LockedFile
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Crypt-PasswdMD5>=0:../../security/p5-Crypt-PasswdMD5
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/Authen/Htpasswd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
