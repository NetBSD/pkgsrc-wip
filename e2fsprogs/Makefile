# $NetBSD: Makefile,v 1.2 2003/12/04 18:28:56 jeremy-c-reed Exp $
#

DISTNAME=	e2fsprogs-1.34
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/} \
		ftp://ftp.dei.uc.pt/.d4/linuxberg/files/console/system/ \
		ftp://tsx-11.mit.edu/pub/linux/packages/ext2fs/ \
		ftp://ftp.gwdg.de/pub/linux/mirrors/tsx-11/packages/ext2fs/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

#BUILD_DEPENDS=	gettext>=0.11.5:../../devel/gettext
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_MAKEINFO=		YES
USE_BUILDLINK2=		YES # so USE_PKGLOCALEDIR will work
USE_PKGLOCALEDIR=	YES
INFO_FILES=		libext2fs.info

CONFIGURE_ENV+=		ac_cv_path_MSGFMT=${LOCALBASE}/bin/msgfmt
CONFIGURE_ARGS+=	--enable-elf-shlibs
#--with-libintl-prefix=

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-fsck
.endif

pre-build:
	# XXX po/ files are not writable by regular user
	${CHMOD} u+w ${WRKSRC}/po/*

post-install:
	# install headers too
	cd ${WRKSRC} && ${MAKE} install-libs

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
