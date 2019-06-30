# $NetBSD: Makefile,v 1.152 2019/01/09 19:09:02 adam Exp $

ORIGINAL_PACKAGE=       ../../graphics/freetype2

ABI?=           	32
ORIGINALPKG!=		make -C ${ORIGINAL_PACKAGE}	
PKGNAME=		compat${ABI}_freetype-2.10.0

# XXX make a definition for netbsd archs.
LIBABISUFFIX?=          /32
CONFIGURE_ARGS+=        --libdir=${PREFIX}/lib${LIBABISUFFIX}
CFLAGS+=                -m32

remove-non-libraries:
	echo "Removing non-compat library package content"
	find ${DESTDIR}${PREFIX} -path ${DESTDIR}${PREFIX}/lib${LIBABISUFFIX} -prune -o -type f -exec ${RM} {} +

post-install: remove-non-libraries

GENERATE_PLIST= ${SED} -n '/^lib/ s;lib;lib${LIBABISUFFIX};p' ${ORIGINAL_PACKAGE}/PLIST;

.include "${ORIGINAL_PACKAGE}/Makefile"
