library(data.table)

gen_name = function() {
  return(paste0(sample(letters, sample(3:7, 1)), collapse = ""))
}

d = data.table(first_name = character(), last_name = character(), gender = character())

for (i in 1:50) {
  d = rbindlist(list(d, list(gen_name(), gen_name(), sample(c("m", "f"), 1))))
}

fwrite(d, "sample_students.csv")