# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 18:58:36 xtraeme Exp $
#

DISTNAME=	pdb2ldif-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.uslinux.net/software/packages/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uslinux.net/software/pkginfo.php?pkg=pdb2ldif
COMMENT=	Converts Palm Address Book PDB files into an LDAP-usable LDIF file

DEPENDS+=	p5-Palm>=1.3.0:../../devel/p5-Palm

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdb2ldif ${PREFIX}/bin/pdb2ldif

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
