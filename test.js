function calculateDaysBetweenDate(begin, end) {
    const beginDate = new Date(begin);
    const endDate = new Date(end);

    // Calculate the difference in milliseconds
    const differenceInTime = endDate.getTime() - beginDate.getTime();

    // Calculate the difference in days
    const differenceInDays = Math.ceil(differenceInTime / (1000 * 3600 * 24));

    return differenceInDays;
}